# ============================================================
# YOU'RE FIRED - Model : UA Importer Configuration
# ============================================================
import unreal

class MUaImporterData:
    """Model: Configuracion de rutas y opciones de importacion de assets."""

    def __init__(self, source_directory="/Import/Raw", target_directory="/Game/Assets"):
        self.source_directory = source_directory
        self.target_directory = target_directory
        self.b_auto_replace = True
