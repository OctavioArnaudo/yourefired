# ============================================================
# YOU'RE FIRED - Service : Flipbook Builder Service
# ============================================================
import unreal

class SFbBuilderService:
    """Service: Creacion y compilacion dinamica de Flipbooks."""

    def build_flipbook_from_sprites(self, flipbook_name, sprite_list):
        unreal.log(f"[SFbBuilderService] Compilando flipbook '{flipbook_name}' con {len(sprite_list)} frames.")
        return True
