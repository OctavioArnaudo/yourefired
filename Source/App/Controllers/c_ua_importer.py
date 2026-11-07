# ============================================================
# YOU'RE FIRED - Controller : UA Importer Orchestrator
# ============================================================
import unreal

class CUaImporterController:
    """Controller: Gestion de peticiones de importacion de assets."""

    def request_asset_import(self, source_path, destination_path):
        unreal.log(f"[CUaImporterController] Solicitando importacion de {source_path} hacia {destination_path}")
        return True
