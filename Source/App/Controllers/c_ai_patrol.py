# ============================================================
# YOU'RE FIRED - Controller: AI Patrol & Enemy Navigation
# ============================================================
import unreal
import m_ai_patrol

def assign_patrol_route(enemy_actor, route_name="Office_Main_Patrol"):
    """Controller: Asigna una ruta de patrullaje a un enemigo (Coworker/Supervisor)."""
    if not enemy_actor or not enemy_actor.is_valid():
        return False

    waypoints = m_ai_patrol.get_patrol_waypoints(route_name)
    unreal.log(f"[Controller:AiPatrol] Asignada ruta '{route_name}' ({len(waypoints)} waypoints) a {enemy_actor.get_actor_label()}.")

    enemy_actor.set_actor_label(f"{enemy_actor.get_actor_label()}_Patrolling")
    return True

def setup_office_enemy_patrols():
    """Controller: Configura las rutas de patrulla para todos los enemigos de la oficina."""
    for actor in unreal.EditorLevelLibrary.get_all_level_actors():
        if actor and actor.is_valid():
            label = actor.get_actor_label()
            if "Coworker" in label:
                assign_patrol_route(actor, "Coworker_Cubicle_Patrol")
            elif "Supervisor" in label:
                assign_patrol_route(actor, "Supervisor_Executive_Patrol")
