# ============================================================
# YOU'RE FIRED - Controller: Player Actor Spawner
# ============================================================
import unreal
import c_actor_spawner

def spawn_player_actor(name="Player", position=(0, -1200, 100)):
    """Controller: Spawnea el personaje del jugador utilizando c_actor_spawner."""
    unreal.log("[Controller:PlayerActor] Spawning player character component...")
    return c_actor_spawner.spawn_actor(name, "/Script/App.PlayerCharacter", position)
