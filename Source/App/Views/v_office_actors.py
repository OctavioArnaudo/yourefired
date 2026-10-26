# ============================================================
# YOU'RE FIRED - View: Office Characters & Actors Layout
# ============================================================
import unreal
import c_actor_spawner

def place_office_actors():
    """View: Posiciona exclusivamente los personajes (Jugador, Compañeros, Supervisores) en la oficina."""
    unreal.log("[View:OfficeActors] Posicionando personaje del jugador y enemigos 2D...")

    # Jugador
    c_actor_spawner.spawn_actor("Player", "/Script/App.CPlayerCharacter", (0, -1200, 0))

    # Compañeros de trabajo
    coworker_positions = [(-800, 300, 0), (800, -300, 0), (0, 700, 0)]
    for idx, pos in enumerate(coworker_positions):
        c_actor_spawner.spawn_actor(f"Coworker_{idx+1:02d}", "/Script/App.CCoworkerEnemy", pos)

    # Supervisores
    supervisor_positions = [(-400, -100, 0), (400, 100, 0)]
    for idx, pos in enumerate(supervisor_positions):
        c_actor_spawner.spawn_actor(f"Supervisor_{idx+1:02d}", "/Script/App.CSupervisorEnemy", pos)
