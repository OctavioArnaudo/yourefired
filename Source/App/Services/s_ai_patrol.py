# ============================================================
# YOU'RE FIRED - Service: AI Patrol Calculation & Routing
# ============================================================
import unreal
import m_ai_patrol
import s_patrol

def calculate_next_waypoint(current_index, route_name):
    """Service: Calcula el índice del siguiente waypoint en la ruta circular."""
    waypoints = m_ai_patrol.get_patrol_waypoints(route_name)
    if not waypoints:
        return 0
    return (current_index + 1) % len(waypoints)

def execute_ai_patrol(character_actor, route_name):
    """Service: Ejecuta el patrullaje de IA reutilizando el servicio base s_patrol."""
    unreal.log(f"[Service:AiPatrol] Ejecutando patrulla de IA para ruta '{route_name}'.")
    return s_patrol.execute_patrol_step(character_actor, (0.0, 0.0, 0.0))
