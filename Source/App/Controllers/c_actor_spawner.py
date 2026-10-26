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

import s_ua_normalizer

def spawn_actor(name, class_path, position, rotation=None):
    """Component: Spawnea un actor por clase C++, Blueprint normalizado o fallback nativo."""
    if rotation is None:
        rotation = unreal.Rotator(0, 0, 0)

    actor_class = None

    # 1. Intentar cargar la clase o ruta especificada
    if class_path:
        try:
            actor_class = unreal.load_class(None, class_path)
        except Exception:
            pass

    # 2. Si no existe, normalizar el nombre (ej. Coworker_01 -> SM_CoworkerEnemy) y buscar el BP base
    if not actor_class:
        base_name = s_ua_normalizer.get_normalized_asset_name(name)
        bp_path = f"/Game/YoureFired/Blueprints/BP_{base_name}.BP_{base_name}_C"
        try:
            actor_class = unreal.load_class(None, bp_path)
        except Exception:
            pass

    # 3. Fallback final a clases nativas de Unreal Engine
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
