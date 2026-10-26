# ============================================================
# YOU'RE FIRED - Model: AI Patrol Waypoint Data Model
# ============================================================
import unreal

PATROL_ROUTES = {
    "Coworker_Cubicle_Patrol": [
        (-800, 300, 75), (-800, -300, 75), (0, 700, 75), (800, 300, 75)
    ],
    "Supervisor_Executive_Patrol": [
        (-400, -100, 75), (400, 100, 75), (0, 1200, 75), (0, -1000, 75)
    ],
    "Office_Main_Patrol": [
        (-1000, 1000, 75), (1000, 1000, 75), (1000, -1000, 75), (-1000, -1000, 75)
    ]
}

def get_patrol_waypoints(route_name):
    """Model: Retorna las coordenadas de waypoints para una ruta específica."""
    return PATROL_ROUTES.get(route_name, PATROL_ROUTES["Office_Main_Patrol"])
