# ============================================================
# YOU'RE FIRED - Controller: Player Character Orchestrator
# ============================================================
import unreal
import c_player_actor
import c_player_xy_movement
import c_player_imc
import c_player_fb

def setup_player_character(location=(0, -1200, 0)):
    """Controller: Decomprime la creación del personaje delegando en componentes y controladores dedicados."""
    unreal.log("[Controller:PlayerCharacter] Iniciando inicialización descomprimida del jugador...")

    # 1. Spawner unitario del actor
    player = c_player_actor.spawn_player_actor("Player", location)

    if player and player.is_valid():
        # 2. Delegar configuración de movimiento 2D a c_player_xy_movement
        c_player_xy_movement.apply_xy_movement(player, unreal.Vector2D(0, 0))

        # 3. Delegar configuración de Enhanced Input a c_player_imc
        c_player_imc.setup_player_mapping_context(player)

        # 4. Delegar configuración de animación 2D a c_player_fb
        c_player_fb.update_player_flipbook_state(player, is_moving=False)

        unreal.log("[Controller:PlayerCharacter] Inicialización completada con éxito.")
        return player

    return None
