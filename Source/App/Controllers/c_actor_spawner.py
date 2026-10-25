# ============================================================
# YOU'RE FIRED - Controller / Component: Actor Spawner
# ============================================================
import unreal

def spawn_actor(name, class_path, position, rotation=None):
    """Component: Spawnea un actor por clase con soporte para assets propios y fallback nativo."""
    if rotation is None:
        rotation = unreal.Rotator(0, 0, 0)

    actor_class = unreal.load_class(None, class_path)
    if not actor_class:
        if "Character" in class_path or "Worker" in name or "Coworker" in name or "Supervisor" in name:
            actor_class = unreal.Character
        else:
            actor_class = unreal.Actor

    actor = unreal.EditorLevelLibrary.spawn_actor_from_class(actor_class, unreal.Vector(*position), rotation)
    if actor:
        actor.set_actor_label(name)
        unreal.log("[Component:ActorSpawner] Spawneado actor: " + name)
    return actor
