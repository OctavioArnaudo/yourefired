# ============================================================
# YOU'RE FIRED - View: Office Level Layout Orchestrator
# ============================================================
import unreal
import c_actor_spawner
import c_camera
import c_light
import v_office_perimeter
import v_office_cubicles

def build_office_layout():
    unreal.log("[OfficeLevel] Orquestando diseño modular de la oficina...")

    # 1. Perímetro y Suelo
    v_office_perimeter.build_office_perimeter(1600.0)

    # 2. Cubículos
    v_office_cubicles.build_office_cubicles()

    # 3. Jugador, Enemigos e Ítems
    c_actor_spawner.spawn_actor("Player", "/Script/App.CPlayerCharacter", (0, -1200, 100))

    coworker_positions = [(-800, 300, 75), (800, -300, 75), (0, 700, 75)]
    for idx, pos in enumerate(coworker_positions):
        c_actor_spawner.spawn_actor(f"Coworker_{idx+1:02d}", "/Script/App.CCoworkerEnemy", pos)

    supervisor_positions = [(-400, -100, 75), (400, 100, 75)]
    for idx, pos in enumerate(supervisor_positions):
        c_actor_spawner.spawn_actor(f"Supervisor_{idx+1:02d}", "/Script/App.CSupervisorEnemy", pos)

    c_actor_spawner.spawn_actor("CoffeeItem", "/Script/App.CCoffeePickup", (300, -800, 60))
    c_actor_spawner.spawn_actor("SignatureItem", "/Script/App.CSignaturePickup", (0, -600, 60))
    c_actor_spawner.spawn_actor("FloorExit_Door", "/Script/App.CDoor", (0, 1500, 100))

    # 4. Cámara e Iluminación en tiempo real
    c_camera.spawn_or_update_camera("Office_TopDownCamera", (0, 0, 2600), (-90, 0, 0))
    c_light.setup_directional_light("Office_DirectionalLight", (0, 0, 1000), (-50, -30, 0), 10.0)
    c_light.setup_sky_light("Office_SkyLight", (0, 0, 500), 2.0)
