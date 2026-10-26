# ============================================================
# YOU'RE FIRED - Controller / Component: Actor Spawner
# ============================================================
import unreal

def spawn_actor(name, class_path, position, rotation=None):
    """Component: Spawnea un actor por clase C++, Blueprint o fallback nativo sin advertencias."""
    if rotation is None:
        rotation = unreal.Rotator(0, 0, 0)

    actor_class = None

    # 1. Intentar cargar la clase o ruta especificada
    if class_path:
        try:
            actor_class = unreal.load_class(None, class_path)
        except Exception:
            pass

    # 2. Si no existe, intentar buscar el Blueprint correspondiente en Content/YoureFired/Blueprints/
    if not actor_class:
        bp_path = f"/Game/YoureFired/Blueprints/BP_{name}.BP_{name}_C"
        try:
            actor_class = unreal.load_class(None, bp_path)
        except Exception:
            pass

    # 3. Fallback final a clases nativas de Unreal Engine si no hay BP ni C++ compilado
    if not actor_class:
        if "Character" in (class_path or "") or "Player" in name or "Coworker" in name or "Supervisor" in name:
            actor_class = unreal.Character
        else:
            actor_class = unreal.Actor

    actor = unreal.EditorLevelLibrary.spawn_actor_from_class(actor_class, unreal.Vector(*position), rotation)
    if actor:
        actor.set_actor_label(name)
        unreal.log(f"[Component:ActorSpawner] Spawneado actor '{name}' exitosamente.")
    return actor
