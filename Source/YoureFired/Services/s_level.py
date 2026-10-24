import unreal
import level_builder_util as legacy_utils
from . import s_gamemode

def initialize_level(level_path, gamemode_path):
    """Service: Orquesta la inicialización de un nuevo nivel o carga uno existente con su GameMode."""
    legacy_utils.open_or_create_level(level_path)
    s_gamemode.set_level_gamemode(level_path, gamemode_path)
    unreal.log("[Service:Level] Nivel inicializado: " + level_path)
