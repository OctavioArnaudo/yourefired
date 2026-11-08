# ============================================================
# YOU'RE FIRED - Controller : Pickup Actor Instance Controller
# ============================================================
import sys
import os

_current_dir = os.path.dirname(os.path.abspath(__file__))
_app_dir = os.path.dirname(_current_dir) if os.path.basename(_current_dir) in ['Models', 'Controllers', 'Views', 'Services', 'Interfaces'] else _current_dir
for _folder in ['', 'Models', 'Controllers', 'Views', 'Services', 'Interfaces']:
    _path = os.path.join(_app_dir, _folder)
    if _path not in sys.path:
        sys.path.insert(0, _path)

import unreal
import traceback
from m_pickup_actor_instance import MPickupActorInstanceData

def get_editor_world_subsystem():
    try:
        subsystem = unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem)
        if subsystem:
            return subsystem.get_editor_world()
    except Exception:
        pass
    return unreal.EditorLevelLibrary.get_editor_world()

def spawn_actor_subsystem(cls, location, rotation):
    try:
        subsystem = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
        if subsystem:
            return subsystem.spawn_actor_from_class(cls, location, rotation)
    except Exception:
        pass
    return unreal.EditorLevelLibrary.spawn_actor_from_class(cls, location, rotation)

def spawn_and_configure_pickup():
    unreal.log("[CPickupActorInstance] Starting health pickup rhombus spawn & setup...")

    try:
        world = get_editor_world_subsystem()
        if not world:
            unreal.log_error("[CPickupActorInstance] ERROR: No active editor world found.")
            return

        possible_paths = [
            "/Script/App.CPickupActorInstance",
            "/Script/App.PickupActorInstance",
            "/Script/App.ACPickupActorInstance"
        ]

        cls = None
        for path in possible_paths:
            unreal.log(f"[CPickupActorInstance] Intentando cargar clase desde: {path}")
            cls = unreal.load_class(None, path)
            if cls:
                unreal.log(f"[CPickupActorInstance] ¡Clase cargada exitosamente desde: {path}!")
                break

        if not cls:
            unreal.log_error("[CPickupActorInstance] CRITICAL ERROR: Could not load ACPickupActorInstance from any known path.")
            return

        location = unreal.Vector(200.0, 0.0, 200.0)
        rotation = unreal.Rotator(0.0, 0.0, 0.0)

        spawned_pickup = spawn_actor_subsystem(cls, location, rotation)
        if spawned_pickup:
            unreal.log(f"[CPickupActorInstance] Health pickup rhombus spawned successfully: {spawned_pickup.get_name()} at {location}")
        else:
            unreal.log_error("[CPickupActorInstance] ERROR: Failed to spawn health pickup actor.")

    except Exception as e:
        unreal.log_error(f"[CPickupActorInstance] Exception in Python script: {str(e)}")
        unreal.log_error(traceback.format_exc())

class CPickupActorInstanceController:
    """Controller: Gestiona la recoleccion y efecto de vida del pickup rombo."""

    def __init__(self):
        self.model = MPickupActorInstanceData()

    def process_pickup(self, player_actor):
        if player_actor and player_actor.is_valid():
            unreal.log(f"[CPickupActorInstanceController] Pickup rombo recolectado. Curando {self.model.heal_amount} HP.")
            return True
        return False

if __name__ == "__main__":
    spawn_and_configure_pickup()
