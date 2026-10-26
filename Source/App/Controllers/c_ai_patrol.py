# ============================================================
# YOU'RE FIRED - Controller: AI Patrol Route Assignment
# ============================================================
import unreal
import m_ai_patrol

def assign_patrol_route(enemy_actor, route_name="Office_Main_Patrol"):
    """Controller: Asigna de forma unitaria una ruta de patrullaje a un actor enemigo."""
    if not enemy_actor or not enemy_actor.is_valid():
        return False

    waypoints = m_ai_patrol.get_patrol_waypoints(route_name)
    unreal.log(f"[Controller:AiPatrol] Asignada ruta '{route_name}' ({len(waypoints)} waypoints) a {enemy_actor.get_actor_label()}.")
    enemy_actor.set_actor_label(f"{enemy_actor.get_actor_label()}_Patrolling")
    return True
