import unreal

def spawn_actor(name, class_path, position, rotation=None):
    """Spawnea un actor por clase."""
    if rotation is None:
        rotation = unreal.Rotator(0, 0, 0)

    actor_class = unreal.load_class(None, class_path)
    if not actor_class:
        unreal.log_error("No se pudo cargar la clase: " + class_path)
        return None

    actor = unreal.EditorLevelLibrary.spawn_actor_from_class(actor_class, unreal.Vector(*position), rotation)
    if actor:
        actor.set_actor_label(name)
        unreal.log("[ActorSpawner] Spawneado: " + name)
    return actor

def spawn_mesh(name, mesh_path, position, scale=(1, 1, 1), rotation=None):
    """Spawnea un StaticMeshActor."""
    if rotation is None:
        rotation = unreal.Rotator(0, 0, 0)

    mesh = unreal.EditorAssetLibrary.load_asset(mesh_path)
    if not mesh:
        unreal.log_error("No se pudo cargar mesh: " + mesh_path)
        return None

    actor = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.StaticMeshActor, unreal.Vector(*position), rotation)
    if actor:
        actor.set_actor_label(name)
        actor.set_actor_scale3d(unreal.Vector(*scale))
        actor.static_mesh_component.set_static_mesh(mesh)
    return actor
