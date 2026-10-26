# ============================================================
# YOU'RE FIRED - View: AI Patrol Waypoint Visualization
# ============================================================
import unreal
import m_ai_patrol

def render_patrol_waypoints_preview(route_name="Coworker_Cubicle_Patrol"):
    """View: Dibuja/visualiza waypoints de patrulla en el editor para previsualización."""
    waypoints = m_ai_patrol.get_patrol_waypoints(route_name)
    unreal.log(f"[View:AiPatrol] Renderizando {len(waypoints)} waypoints de la ruta '{route_name}'.")
