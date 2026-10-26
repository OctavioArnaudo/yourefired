# ============================================================
# YOU'RE FIRED - Service: Master Placeholder Orchestrator
# ============================================================
import unreal
import s_static_placeholder
import s_dynamic_placeholder
import s_raw_placeholder
import s_ua_importer

def ensure_asset_placeholders():
    """Service: Orquesta la verificación, creación de archivos .png/.fbx físicos y generación de placeholders .uasset."""
    unreal.log("[Service:Placeholder] === INICIANDO VERIFICACION E IMPORTACION DE ASSETS ===")

    # 1. Generar archivos físicos .png y .fbx en RawAssets/ si no existen
    s_raw_placeholder.ensure_raw_placeholders()

    # 2. Importar automáticamente assets primarios .png y .fbx de RawAssets/ a Unreal Content
    s_ua_importer.import_all_raw_assets()

    # 3. Generar y verificar placeholders .uasset
    s_static_placeholder.ensure_static_placeholders()
    s_dynamic_placeholder.ensure_dynamic_placeholders()

    unreal.log("[Service:Placeholder] === VERIFICACION E IMPORTACION COMPLETADA ===")
