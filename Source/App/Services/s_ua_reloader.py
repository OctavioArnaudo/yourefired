# ============================================================
# YOU'RE FIRED - Service: Unreal Python Module Cache Reloader
# ============================================================
import unreal
import sys

def reload_app_modules():
    """Service: Purga la caché de módulos de Python en Unreal Editor para forzar la recarga desde disco."""
    unreal.log("[Service:UaReloader] Purgando caché de módulos de Python en Unreal Editor...")
    for mod_name in list(sys.modules.keys()):
        if mod_name.startswith(('s_', 'v_', 'c_', 'm_', 'i_')) or mod_name in ['level_builder_util']:
            del sys.modules[mod_name]
