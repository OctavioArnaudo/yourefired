# ============================================================
# YOU'RE FIRED - Controller / Component: Actor Spawner
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

def get_actor_by_label(label):
    """Encuentra un actor existente en el nivel activo por su etiqueta para evitar duplicados."""
    for actor in unreal.EditorLevelLibrary.get_all_level_actors():
        if actor and actor.get_actor_label() == label:
            return actor
    return None

def apply_color_to_actor_components(actor, name):
    """Component: Aplica material y color dinámico desde s_color a los componentes visuales de un Actor/Character."""
    if not actor:
        return

    color = s_color.get_color_for_name(name)
    mat = s_ua_loader.get_asset_with_fallback("/Game/YoureFired/Materials/M_OfficeStyle.M_OfficeStyle", "/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial")

    # Si es un Character con componente de malla
    if hasattr(actor, "mesh") and actor.mesh:
        if mat:
            actor.mesh.set_material(0, mat)
        dyn_mat = actor.mesh.create_and_set_material_instance_dynamic(0)
        if dyn_mat:
            for param in ["Color", "BaseColor", "Base Color", "Tint", "Albedo"]:
                try:
                    dyn_mat.set_vector_parameter_value(param, color)
                except Exception:
                    pass

    # Si tiene static_mesh_component
    if hasattr(actor, "static_mesh_component") and actor.static_mesh_component:
        if mat:
            actor.static_mesh_component.set_material(0, mat)
        dyn_mat = actor.static_mesh_component.create_and_set_material_instance_dynamic(0)
        if dyn_mat:
            for param in ["Color", "BaseColor", "Base Color", "Tint", "Albedo"]:
                try:
                    dyn_mat.set_vector_parameter_value(param, color)
                except Exception:
                    pass

def spawn_actor(name, class_path, position, rotation=None):
    """Component: Reutiliza un actor existente o spawnea uno nuevo sin generar duplicados ni advertencias."""
    if rotation is None:
        rotation = unreal.Rotator(0, 0, 0)

    # 1. Reutilizar si ya existe un actor homónimo en la escena
    existing_actor = get_actor_by_label(name)
    if existing_actor:
        existing_actor.set_actor_location_and_rotation(unreal.Vector(*position), rotation, False, True)
        apply_color_to_actor_components(existing_actor, name)
        unreal.log(f"[Component:ActorSpawner] Reutilizado actor existente '{name}' en la escena.")
        return existing_actor

    actor_class = None

    # 2. Intentar obtener la clase directamente desde el módulo 'unreal' de Python si es una ruta C++
    if class_path and class_path.startswith("/Script/"):
        cls_name = class_path.split('.')[-1]
        actor_class = getattr(unreal, cls_name, None)
        if not actor_class:
            actor_class = getattr(unreal, "C" + cls_name, None)

    # 3. Si es una ruta de Blueprint en Content, verificar primero con does_asset_exist
    if not actor_class and class_path and class_path.startswith("/Game/"):
        pkg_path = class_path.split('.')[0]
        if unreal.EditorAssetLibrary.does_asset_exist(pkg_path):
            try:
                actor_class = unreal.load_class(None, class_path)
            except Exception:
                pass

    # 4. Si no existe, normalizar el nombre (removiendo prefijo SM_) y verificar silenciadamente el BP base
    if not actor_class:
        base_name = s_ua_normalizer.get_normalized_asset_name(name)
        bp_name = base_name[3:] if base_name.startswith("SM_") else base_name
        bp_package = f"/Game/YoureFired/Blueprints/BP_{bp_name}"
        bp_path = f"{bp_package}.BP_{bp_name}_C"

        if unreal.EditorAssetLibrary.does_asset_exist(bp_package):
            try:
                actor_class = unreal.load_class(None, bp_path)
            except Exception:
                pass

    # 5. Fallback final a clases nativas de Unreal Engine
    if not actor_class:
        if "Character" in (class_path or "") or "Player" in name or "Coworker" in name or "Supervisor" in name:
            actor_class = unreal.Character
        else:
            actor_class = unreal.Actor

    actor = unreal.EditorLevelLibrary.spawn_actor_from_class(actor_class, unreal.Vector(*position), rotation)
    if actor:
        actor.set_actor_label(name)
        apply_color_to_actor_components(actor, name)
        unreal.log(f"[Component:ActorSpawner] Spawneado nuevo actor '{name}' exitosamente.")
    return actor
