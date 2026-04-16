def encode_to_rbn(data):
    rbn = {
        "leader_states": set(),
        "contributor_states": set(),
        "sigma_send": set(),
        "sigma_recv": set(),
        "leader_transitions": [],
        "contributor_transitions": [],
        "initial_leader": data["env_initial"],
        "initial_counts": {}
    }

    # -------------------------
    # 1. contributor states
    # -------------------------
    rbn["contributor_states"] = set(data["state_capacity"].keys())

    # initial counts (from initial assignment)
    for a, s in data["agent_positions"].items():
        rbn["initial_counts"][s] = rbn["initial_counts"].get(s, 0) + 1

    # -------------------------
    # 2. leader states
    # -------------------------
    rbn["leader_states"] = set(data["env_states"])

    # -------------------------
    # 3. encode transitions
    # -------------------------
    for (curr, agent, env_act, act, nxt) in data["transitions"]:

        # contributor receive transition
        rbn["contributor_transitions"].append({
            "from": curr,
            "recv": f"?({act},{env_act})",
            "to": nxt
        })

        # leader broadcast transition
        rbn["leader_transitions"].append({
            "from": curr,
            "send": f"!({act},{env_act})",
            "to": curr  # environment unchanged in your model
        })

        rbn["sigma_send"].add(f"!({act},{env_act})")
        rbn["sigma_recv"].add(f"?({act},{env_act})")

    return rbn