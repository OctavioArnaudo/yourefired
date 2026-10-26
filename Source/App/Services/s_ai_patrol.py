# ============================================================
# YOU'RE FIRED - Service: AI Patrol Calculation & Routing
# ============================================================
import unreal
import m_ai_patrol

def calculate_next_waypoint(current_index, route_name):
    """Service: Calcula el índice del siguiente waypoint en la ruta circular."""
    waypoints = m_ai_patrol.get_patrol_waypoints(route_name)
    if not waypoints:
        return 0
    return (current_index + 1) % len(waypoints)
