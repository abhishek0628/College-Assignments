# # # def parse_input(text):
# # #     sections = text.split("#")

# # #     agent_block = sections[1].splitlines()
# # #     env_block = sections[2].splitlines()

# # #     agent_states = {}
# # #     agents = []
# # #     transitions = []
# # #     env = {}

# # #     init = {}

# # #     mode = "states"

# # #     # ---------- AGENT SECTION ----------
# # #     for line in agent_block:
# # #         line = line.strip()
# # #         if not line:
# # #             continue

# # #         # state capacities
# # #         if ":" in line and not line.split(":")[0].strip().startswith("a"):
# # #             k, v = line.split(":", 1)
# # #             try:
# # #                 agent_states[k.strip()] = int(v.strip().split(",")[0])
# # #             except:
# # #                 agent_states[k.strip()] = 0

# # #         # agent list
# # #         elif line.startswith("a") and "," in line:
# # #             agents = [x.strip() for x in line.split(",")]

# # #         # initial mapping
# # #         elif ":" in line and any(a in line for a in agents):
# # #             k, v = line.split(":")
# # #             init[k.strip()] = [x.strip() for x in v.split(",")]

# # #         # transitions
# # #         elif "," in line:
# # #             parts = [x.strip() for x in line.split(",")]
# # #             if len(parts) >= 5:
# # #                 transitions.append(parts)

# # #     # ---------- ENV SECTION ----------
# # #     env_states = []
# # #     env_actions = []
# # #     env_trans = []

# # #     for line in env_block:
# # #         line = line.strip()
# # #         if not line:
# # #             continue

# # #         if "," in line and ":" not in line:
# # #             env_states = [x.strip() for x in line.split(",")]

# # #         elif len(line.split()) == 1:
# # #             env_actions.append(line.strip())

# # #         elif ":" in line:
# # #             k, v = line.split(":")
# # #             env_trans.append((k.strip(), v.strip()))

# # #     return {
# # #         "states": agent_states,
# # #         "agents": agents,
# # #         "transitions": transitions,
# # #         "env_states": env_states,
# # #         "env_actions": env_actions,
# # #         "env_trans": env_trans,
# # #         "initial": init
# # #     }
# # def parse_input(text):
# #     sections = text.split("#")

# #     agent_block = sections[1].splitlines()
# #     env_block = sections[2].splitlines()

# #     agent_states = {}
# #     agents = []
# #     transitions = []
# #     init = {}

# #     env_states = []
# #     env_actions = []
# #     env_trans = []

# #     # -------------------------
# #     # AGENT SECTION
# #     # -------------------------
# #     for line in agent_block:
# #         line = line.strip()
# #         if not line:
# #             continue

# #         # capacities: l0: 1, l1: 1 ...
# #         if ":" in line and "a" not in line.split(":")[0]:
# #             k, v = line.split(":", 1)
# #             try:
# #                 agent_states[k.strip()] = int(v.split(",")[0].strip())
# #             except:
# #                 pass
# #             continue

# #         # agent list: a1, a2
# #         if line.startswith("a") and "," in line:
# #             agents = [x.strip() for x in line.split(",")]
# #             continue

# #         # initial mapping: l0: a1
# #         if ":" in line and any(a in line for a in agents):
# #             k, v = line.split(":", 1)
# #             state = k.strip()
# #             agent_list = [x.strip() for x in v.split(",") if x.strip()]
# #             init[state] = agent_list
# #             continue

# #         # transitions: l0,a1,b,a1,l1
# #         if "," in line:
# #             parts = [x.strip() for x in line.split(",")]
# #             if len(parts) >= 5:
# #                 transitions.append(parts)

# #     # -------------------------
# #     # ENV SECTION
# #     # -------------------------
# #     for line in env_block:
# #         line = line.strip()
# #         if not line:
# #             continue

# #         if "," in line and ":" not in line:
# #             env_states = [x.strip() for x in line.split(",")]
# #             continue

# #         if len(line.split()) == 1:
# #             env_actions.append(line.strip())
# #             continue

# #         if ":" in line:
# #             k, v = line.split(":")
# #             env_trans.append((k.strip(), v.strip()))

# #     return {
# #         "states": agent_states,
# #         "agents": agents,
# #         "transitions": transitions,
# #         "env_states": env_states,
# #         "env_actions": env_actions,
# #         "env_trans": env_trans,
# #         "initial": init
# #     }
# def parse_input(text):
#     sections = text.split("#")

#     if len(sections) < 3:
#         return {
#             "states": {},
#             "agents": [],
#             "transitions": [],
#             "env_states": [],
#             "env_actions": [],
#             "env_trans": [],
#             "initial": {}
#         }

#     agent_block = sections[1].splitlines()
#     env_block = sections[2].splitlines()

#     agent_states = {}
#     agents = []
#     transitions = []
#     init = {}

#     env_states = []
#     env_actions = []
#     env_trans = []

#     # -------------------------
#     # AGENT SECTION
#     # -------------------------
#     for line in agent_block:
#         line = line.strip()
#         if not line:
#             continue

#         # ---------------- capacities ----------------
#         if ":" in line and "a" not in line.split(":")[0]:
#             k, v = line.split(":", 1)
#             try:
#                 agent_states[k.strip()] = int(v.split(",")[0].strip())
#             except:
#                 agent_states[k.strip()] = 0
#             continue

#         # ---------------- agent list ----------------
#         if line.startswith("a") and "," in line:
#             agents = [x.strip() for x in line.split(",")]
#             continue

#         # ---------------- initial mapping FIX ----------------
#         if ":" in line:
#             k, v = line.split(":", 1)

#             state = k.strip()
#             values = v.strip()

#             # only treat as initial if RHS has agents
#             if "a" in values:
#                 init[state] = [x.strip() for x in values.split(",") if x.strip()]
#             continue

#         # ---------------- transitions ----------------
#         if "," in line:
#             parts = [x.strip() for x in line.split(",")]
#             if len(parts) >= 5:
#                 transitions.append(parts)

#     # -------------------------
#     # ENV SECTION
#     # -------------------------
#     for line in env_block:
#         line = line.strip()
#         if not line:
#             continue

#         if "," in line and ":" not in line:
#             env_states = [x.strip() for x in line.split(",")]
#             continue

#         if len(line.split()) == 1:
#             env_actions.append(line.strip())
#             continue

#         if ":" in line:
#             k, v = line.split(":")
#             env_trans.append((k.strip(), v.strip()))

#     return {
#         "states": agent_states,
#         "agents": agents,
#         "transitions": transitions,
#         "env_states": env_states,
#         "env_actions": env_actions,
#         "env_trans": env_trans,
#         "initial": init
#     }

def parse_input(text):
    sections = text.split("#")

    agent_block = []
    env_block = []

    # find sections safely
    for i, sec in enumerate(sections):
        sec = sec.strip().lower()
        if "agent information" in sec:
            agent_block = sections[i].splitlines()
        if "environment information" in sec:
            env_block = sections[i].splitlines()

    agent_states = {}
    agents = []
    transitions = []
    initial_map = {}

    mode = "states"

    for line in agent_block:
        line = line.strip()
        if not line or line.startswith("#"):
            continue

        # state capacities: l0: 1
        if ":" in line and not line.startswith("a"):
            k, v = line.split(":", 1)
            if v.strip().replace(",", "").isdigit():
                agent_states[k.strip()] = int(v.strip())
            else:
                # initial mapping: l0: a1,a2
                init_agents = [x.strip() for x in v.split(",") if x.strip()]
                initial_map[k.strip()] = init_agents

        elif line.startswith("a"):
            agents = [x.strip() for x in line.split(",")]

        elif "," in line and line.count(",") >= 4:
            parts = [x.strip() for x in line.split(",")]
            if len(parts) >= 5:
                transitions.append(parts)

        # fallback initial format: l0
        elif line and ":" not in line and "," not in line:
            if "initial_list" not in initial_map:
                initial_map["initial_list"] = []
            initial_map["initial_list"].append(line.strip())

    # environment parsing
    env_states = []
    env_actions = []
    env_trans = []

    for line in env_block:
        line = line.strip()
        if not line:
            continue

        if "," in line and ":" not in line:
            env_states = [x.strip() for x in line.split(",")]

        elif len(line.split()) == 1:
            env_actions.append(line.strip())

        elif ":" in line:
            k, v = line.split(":", 1)
            env_trans.append((k.strip(), v.strip()))

    # FIX: ensure initial exists
    if "initial_list" in initial_map and not any(":" in l for l in agent_block):
        initial_map = {
            initial_map["initial_list"][0]: initial_map["initial_list"][1:]
        }

    return {
        "states": agent_states,
        "agents": agents,
        "transitions": transitions,
        "env_states": env_states,
        "env_actions": env_actions,
        "env_trans": env_trans,
        "initial": initial_map
    }