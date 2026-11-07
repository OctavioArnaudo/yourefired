# c_enemy_character_instance.py
# Automation script to load, spawn, and configure CEnemyCharacterInstance in the current editor level.

import unreal
import traceback

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

def spawn_and_configure_enemy():
    unreal.log("[CEnemyCharacterInstance] Starting enemy spawn & setup...")

    try:
        world = get_editor_world_subsystem()
        if not world:
            unreal.log_error("[CEnemyCharacterInstance] ERROR: No active editor world found.")
            return

        cls = unreal.load_class(None, "/Script/App.CEnemyCharacterInstance")
        if not cls:
            unreal.log_error("[CEnemyCharacterInstance] CRITICAL ERROR: Could not load CEnemyCharacterInstance from /Script/App.CEnemyCharacterInstance.")
            return

        unreal.log(f"[CEnemyCharacterInstance] Enemy class loaded successfully from /Script/App.CEnemyCharacterInstance")

        location = unreal.Vector(300.0, 300.0, 200.0)
        rotation = unreal.Rotator(0.0, 0.0, 0.0)

        spawned_enemy = spawn_actor_subsystem(cls, location, rotation)
        if spawned_enemy:
            unreal.log(f"[CEnemyCharacterInstance] Enemy spawned successfully: {spawned_enemy.get_name()} at {location}")
        else:
            unreal.log_error("[CEnemyCharacterInstance] ERROR: Failed to spawn enemy actor.")

    except Exception as e:
        unreal.log_error(f"[CEnemyCharacterInstance] Exception in Python script: {str(e)}")
        unreal.log_error(traceback.format_exc())

if __name__ == "__main__":
    spawn_and_configure_enemy()
