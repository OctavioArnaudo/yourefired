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

    # Configurar sys.path para incluir todos los submódulos de Source/YoureFired/
    current_dir = os.path.dirname(os.path.abspath(__file__)) # Source/YoureFired
    for subfolder in ['', 'Views', 'Controllers', 'Services', 'Models', 'Interfaces']:
        path = os.path.join(current_dir, subfolder)
        if path not in sys.path:
            sys.path.insert(0, path)

    try:
        # 1. Delegar generación de placeholders al servicio dedicado
        import s_placeholder_manager
        s_placeholder_manager.ensure_asset_placeholders()

        # 2. Delegar construcción de niveles al orquestador de mundos
        import v_world_levels
        v_world_levels.generate_all_levels()

        unreal.log("[YoureFiredMaster] ========================================")
        unreal.log("[YoureFiredMaster] ¡SECUENCIA MAESTRA COMPLETADA CON EXITO!")
        unreal.log("[YoureFiredMaster] ========================================")
    except Exception as e:
        unreal.log_error("[YoureFiredMaster] ERROR CRITICO EN LA SECUENCIA MAESTRA: " + str(e))
        unreal.log_error(traceback.format_exc())

if __name__ == "__main__":
    main()
