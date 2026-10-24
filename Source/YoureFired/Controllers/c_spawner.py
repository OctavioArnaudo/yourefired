import unreal
import sys
import os

current_dir = os.path.dirname(os.path.abspath(__file__))
yourefired_dir = os.path.dirname(current_dir)
services_dir = os.path.join(yourefired_dir, 'Services')
if services_dir not in sys.path:
    sys.path.append(services_dir)

import s_asset_loader

DEFAULT_MAT_PATH = "/Game/LevelPrototyping/Materials/M_PrototypeGrid.M_PrototypeGrid"
CUSTOM_MAT_PATH = "/Game/YoureFired/Materials/M_OfficeStyle.M_OfficeStyle"

def spawn_actor(name, class_path, position, rotation=None):
    """Component: Spawnea un actor por clase."""
    if rotation is None:
        rotation = unreal.Rotator(0, 0, 0)

    actor_class = unreal.load_class(None, class_path)
    if not actor_class:
        unreal.log_error("No se pudo cargar la clase: " + class_path)
        return None

    actor = unreal.EditorLevelLibrary.spawn_actor_from_class(actor_class, unreal.Vector(*position), rotation)
    if actor:
        actor.set_actor_label(name)
        unreal.log("[Component:Spawner] Spawneado: " + name)
    return actor

def spawn_mesh(name, default_mesh_path, position, scale=(1, 1, 1), rotation=None):
    """Component: Spawnea un StaticMeshActor usando fallback inteligente a assets propios si existen."""
    if rotation is None:
        rotation = unreal.Rotator(0, 0, 0)

    custom_mesh_path = f"/Game/YoureFired/Meshes/{name}.{name}"

    mesh = s_asset_loader.get_asset_with_fallback(custom_mesh_path, default_mesh_path)
    if not mesh:
        unreal.log_error("No se pudo cargar mesh para: " + name)
        return None

    actor = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.StaticMeshActor, unreal.Vector(*position), rotation)
    if actor:
        actor.set_actor_label(name)
        actor.set_actor_scale3d(unreal.Vector(*scale))
        actor.static_mesh_component.set_static_mesh(mesh)

        mat = s_asset_loader.get_asset_with_fallback(CUSTOM_MAT_PATH, DEFAULT_MAT_PATH)
        if mat:
            actor.static_mesh_component.set_material(0, mat)

    return actor
