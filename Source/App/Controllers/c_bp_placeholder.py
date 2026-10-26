# ============================================================
# YOU'RE FIRED - Controller: Blueprint Placeholder Controller
# ============================================================
import unreal

def load_bp_class(bp_name):
    """Controller: Carga la clase Blueprint correspondiente por nombre."""
    full_path = f"/Game/YoureFired/Blueprints/BP_{bp_name}.BP_{bp_name}_C"
    try:
        if unreal.EditorAssetLibrary.does_asset_exist(f"/Game/YoureFired/Blueprints/BP_{bp_name}"):
            return unreal.load_class(None, full_path)
    except Exception as e:
        unreal.log_warning(f"[Controller:BP_Placeholder] No se pudo cargar BP_{bp_name}: {e}")
    return None

def spawn_bp_placeholder(bp_name, location=(0,0,0), rotation=None):
    """Controller: Spawnea una instancia de un Blueprint placeholder en la escena actual."""
    if rotation is None:
        rotation = unreal.Rotator(0, 0, 0)

    bp_class = load_bp_class(bp_name)
    if not bp_class:
        unreal.log_warning(f"[Controller:BP_Placeholder] Fallback a actor básico para BP_{bp_name}")
        bp_class = unreal.Character if "Player" in bp_name or "Enemy" in bp_name else unreal.Actor

    actor = unreal.EditorLevelLibrary.spawn_actor_from_class(bp_class, unreal.Vector(*location), rotation)
    if actor:
        actor.set_actor_label(f"BP_{bp_name}_Instance")
        unreal.log(f"[Controller:BP_Placeholder] Spawneado 'BP_{bp_name}_Instance' en escena.")
    return actor
