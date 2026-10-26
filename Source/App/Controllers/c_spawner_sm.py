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
import s_asset_normalizer
import s_color

DEFAULT_MAT_PATH = "/Game/LevelPrototyping/Materials/M_PrototypeGrid.M_PrototypeGrid"
CUSTOM_MAT_PATH = "/Game/YoureFired/Materials/M_OfficeStyle.M_OfficeStyle"

def spawn_mesh(name, default_mesh_path, position, scale=(1, 1, 1), rotation=None):
    """Component: Spawnea un StaticMeshActor usando fallback inteligente y coloración dinámica definida."""
    if rotation is None:
        rotation = unreal.Rotator(0, 0, 0)

    asset_name = s_asset_normalizer.get_normalized_asset_name(name)
    custom_mesh_path = f"/Game/YoureFired/Meshes/{asset_name}.{asset_name}"

    mesh = s_ua_loader.get_asset_with_fallback(custom_mesh_path, default_mesh_path)
    if not mesh:
        unreal.log_error("No se pudo cargar mesh para: " + name)
        return None

    actor = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.StaticMeshActor, unreal.Vector(*position), rotation)
    if actor:
        actor.set_actor_label(name)
        actor.set_actor_scale3d(unreal.Vector(*scale))
        actor.static_mesh_component.set_static_mesh(mesh)

        mat = s_ua_loader.get_asset_with_fallback(CUSTOM_MAT_PATH, DEFAULT_MAT_PATH)
        if mat:
            actor.static_mesh_component.set_material(0, mat)

        # Asignar color dinámico en tiempo real mediante el servicio s_color
        dyn_mat = actor.static_mesh_component.create_and_set_material_instance_dynamic(0)
        if dyn_mat:
            color = s_color.get_color_for_name(name)
            try:
                dyn_mat.set_vector_parameter_value("BaseColor", color)
            except Exception:
                pass
            try:
                dyn_mat.set_vector_parameter_value("Color", color)
            except Exception:
                pass

    return actor
