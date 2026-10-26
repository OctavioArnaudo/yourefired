# ============================================================
# YOU'RE FIRED - Controller: Player Character Logic
# ============================================================
import unreal

def configure_player_character(player_actor):
    """Controller: Configura propiedades iniciales del personaje del jugador en escena."""
    if player_actor:
        unreal.log("[Controller:PlayerCharacter] Configurando propiedades del personaje del jugador.")
        return True
    return False
