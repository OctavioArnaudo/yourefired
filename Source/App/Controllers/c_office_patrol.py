# ============================================================
# YOU'RE FIRED - Controller: Office Enemy Patrol Setup
# ============================================================
import unreal
import c_ai_patrol

def setup_office_enemy_patrols():
    """Controller: Recorre el nivel activo y asigna rutas de patrulla a compañeros y supervisores."""
    for actor in unreal.EditorLevelLibrary.get_all_level_actors():
        if actor and actor.is_valid():
            label = actor.get_actor_label()
            if "Coworker" in label:
                c_ai_patrol.assign_patrol_route(actor, "Coworker_Cubicle_Patrol")
            elif "Supervisor" in label:
                c_ai_patrol.assign_patrol_route(actor, "Supervisor_Executive_Patrol")
