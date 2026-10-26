# ============================================================
# YOU'RE FIRED - Controller / Component: Mesh Spawner
# ============================================================
import unreal
import sys
import os

current_dir = os.path.dirname(os.path.abspath(__file__))
app_dir = os.path.dirname(current_dir)
services_dir = os.path.join(app_dir, 'Services')
if services_dir not in sys.path:
    sys.path.append(services_dir)

import s_ua_loader
import s_ua_normalizer
import s_color

DEFAULT_MAT_PATH = "/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"

def get_actor_by_label(label):
    """Encuentra un actor existente en el nivel activo por su etiqueta para evitar duplicados."""
    for actor in unreal.EditorLevelLibrary.get_all_level_actors():
        if actor and actor.get_actor_label() == label:
            return actor
    return None

def apply_color_to_mesh_actor(actor, name):
    """Component: Aplica colores ultra-vívidos y satura parámetros de iluminación en el material."""
    if not actor or not hasattr(actor, "static_mesh_component") or not actor.static_mesh_component:
        return

    # Asignar material base de motor con soporte de color
    mat = s_ua_loader.get_asset_with_fallback("/Game/YoureFired/Materials/M_OfficeStyle.M_OfficeStyle", DEFAULT_MAT_PATH)
    if mat:
        actor.static_mesh_component.set_material(0, mat)

    dyn_mat = actor.static_mesh_component.create_and_set_material_instance_dynamic(0)
    if dyn_mat:
        color = s_color.get_color_for_name(name)
        # Aplicar color a todos los posibles parámetros vectoriales del shader
        for param in ["Color", "BaseColor", "Base Color", "Tint", "Albedo", "Grid Color", "GridColor", "EmissiveColor", "Emissive Color", "Emissive"]:
            try:
                dyn_mat.set_vector_parameter_value(param, color)
            except Exception:
                pass

def spawn_mesh(name, default_mesh_path, position, scale=(1, 1, 1), rotation=None):
    """Component: Reutiliza o spawnea un StaticMeshActor homónimo aplicando colores vívidos obligatorios."""
    if rotation is None:
        rotation = unreal.Rotator(0, 0, 0)

    asset_name = s_ua_normalizer.get_normalized_asset_name(name)
    custom_mesh_path = f"/Game/YoureFired/Meshes/{asset_name}.{asset_name}"

    mesh = s_ua_loader.get_asset_with_fallback(custom_mesh_path, default_mesh_path)
    if not mesh:
        unreal.log_error("No se pudo cargar mesh para: " + name)
        return None

    # Reutilizar actor homónimo si ya se encuentra en escena
    actor = get_actor_by_label(name)
    if not actor:
        actor = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.StaticMeshActor, unreal.Vector(*position), rotation)
        if actor:
            actor.set_actor_label(name)
    else:
        actor.set_actor_location_and_rotation(unreal.Vector(*position), rotation, False, True)

    if actor:
        actor.set_actor_scale3d(unreal.Vector(*scale))
        if hasattr(actor, "static_mesh_component") and actor.static_mesh_component:
            actor.static_mesh_component.set_static_mesh(mesh)
            apply_color_to_mesh_actor(actor, name)

    return actor
