# ============================================================
# YOU'RE FIRED - Master Entry Point & Sequence Orchestrator
# ============================================================
import unreal
import sys
import os
import traceback

def main():
    unreal.log("[YoureFiredMaster] ========================================")
    unreal.log("[YoureFiredMaster] INICIANDO SECUENCIA MAESTRA DE REGENERACION")
    unreal.log("[YoureFiredMaster] ========================================")

    current_dir = os.path.dirname(os.path.abspath(__file__))
    for subfolder in ['', 'Views', 'Controllers', 'Services', 'Models', 'Interfaces']:
        path = os.path.join(current_dir, subfolder)
        if path not in sys.path:
            sys.path.insert(0, path)

    try:
        import s_ua_reloader
        s_ua_reloader.reload_app_modules()

        import s_placeholder
        s_placeholder.ensure_asset_placeholders()

        import v_world_lvl
        v_world_lvl.generate_all_levels()

        unreal.log("[YoureFiredMaster] ========================================")
        unreal.log("[YoureFiredMaster] ¡SECUENCIA MAESTRA COMPLETADA CON EXITO!")
        unreal.log("[YoureFiredMaster] ========================================")
    except Exception as e:
        unreal.log_error("[YoureFiredMaster] ERROR CRITICO EN LA SECUENCIA MAESTRA: " + str(e))
        unreal.log_error(traceback.format_exc())

if __name__ == "__main__":
    main()
