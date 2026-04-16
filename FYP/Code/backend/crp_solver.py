# from collections import deque

# def check_safety(rbn):

#     initial_map = rbn.get("initial", {})

#     if not initial_map:
#         return {
#             "safe": False,
#             "logs": ["ERROR: No initial state found"],
#             "summary": "INVALID INPUT"
#         }

#     initial_state = list(initial_map.keys())[0]
#     initial_agents = initial_map[initial_state]

#     states = rbn.get("states", {})
#     transitions = rbn.get("graph", {})

#     start = (initial_state, tuple(sorted(initial_agents)))

#     queue = deque([start])
#     visited = set([start])

#     unsafe = {s for s, c in states.items() if c == 0}

#     logs = []
#     logs.append("==== CHECKING SYSTEM SAFETY ====")
#     logs.append(f"Initial State: {initial_state}")
#     logs.append(f"Agents: {initial_agents}")

#     while queue:
#         state, agents = queue.popleft()

#         logs.append(f"Visiting: {state}, agents={agents}")

#         if state in unsafe:
#             logs.append(f"🚨 Unsafe state reached: {state}")
#             return {
#                 "safe": False,
#                 "logs": logs,
#                 "summary": "❌ SYSTEM IS UNSAFE"
#             }

#         for (src, agent), dst_list in transitions.items():
#             if src != state:
#                 continue

#             for dst in dst_list:
#                 new_agents = list(agents)

#                 if agent in new_agents:
#                     new_agents.remove(agent)
#                     new_agents.append(agent)

#                 new_state = (dst, tuple(sorted(new_agents)))

#                 if new_state not in visited:
#                     visited.add(new_state)
#                     queue.append(new_state)

#     logs.append("No unsafe states reachable")

#     return {
#         "safe": True,
#         "logs": logs,
#         "summary": "✅ SYSTEM IS SAFE"
#     }

from collections import deque

def check_safety(rbn):
    initial_map = rbn.get("initial", {})

    if not initial_map:
        return {"safe": False, "reason": "No initial state found in encoded RBN"}

    # handle both formats safely
    if isinstance(initial_map, dict):
        initial_state = list(initial_map.keys())[0]
        initial_agents = initial_map[initial_state]
    else:
        return {"safe": False, "reason": "Invalid initial format"}

    states = rbn.get("states", {})
    transitions = rbn.get("transitions", [])

    start_config = (initial_state, tuple(sorted(initial_agents)))

    queue = deque([start_config])
    visited = {start_config}

    unsafe_states = {s for s, cap in states.items() if cap == 0}

    while queue:
        state, agents = queue.popleft()

        if state in unsafe_states:
            return {
                "safe": False,
                "reason": f"Reached unsafe state: {state}"
            }

        for t in transitions:
            if len(t) < 5:
                continue

            from_state, agent, action, _, to_state = t

            if from_state != state:
                continue

            new_agents = list(agents)

            if agent in new_agents:
                new_agents.remove(agent)
                new_agents.append(agent)

            new_config = (to_state, tuple(sorted(new_agents)))

            if new_config not in visited:
                visited.add(new_config)
                queue.append(new_config)

    return {"safe": True, "reason": "No unsafe state reachable"}