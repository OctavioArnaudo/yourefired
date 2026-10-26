# ============================================================
# YOU'RE FIRED - View: 2D Office Level Layout Orchestrator
# ============================================================
import unreal
import c_actor_spawner
import c_camera
import c_light
import v_office_perimeter
import v_office_cubicles

def build_office_layout():
    unreal.log("[OfficeLevel] Orquestando diseño 2D XY de la oficina...")

    # 1. Perímetro 2D XY
    v_office_perimeter.build_office_perimeter(1600.0)

    # 2. Cubículos 2D XY
    v_office_cubicles.build_office_cubicles()

    # 3. Jugador, Enemigos e Ítems en el plano 2D XY (Z = 0)
    c_actor_spawner.spawn_actor("Player", "/Script/App.CPlayerCharacter", (0, -1200, 0))

    coworker_positions = [(-800, 300, 0), (800, -300, 0), (0, 700, 0)]
    for idx, pos in enumerate(coworker_positions):
        c_actor_spawner.spawn_actor(f"Coworker_{idx+1:02d}", "/Script/App.CCoworkerEnemy", pos)

    supervisor_positions = [(-400, -100, 0), (400, 100, 0)]
    for idx, pos in enumerate(supervisor_positions):
        c_actor_spawner.spawn_actor(f"Supervisor_{idx+1:02d}", "/Script/App.CSupervisorEnemy", pos)

    c_actor_spawner.spawn_actor("CoffeeItem", "/Script/App.CCoffeePickup", (300, -800, 0))
    c_actor_spawner.spawn_actor("SignatureItem", "/Script/App.CSignaturePickup", (0, -600, 0))
    c_actor_spawner.spawn_actor("FloorExit_Door", "/Script/App.CDoor", (0, 1500, 0))

    # 4. Cámara ortográfica 2D e iluminación brillante
    c_camera.spawn_or_update_camera("Office_TopDownCamera", (0, 0, 1500), (-90, 0, 0), ortho_width=2800.0)
    c_light.setup_directional_light("Office_DirectionalLight", (0, 0, 1000), (-90, 0, 0), 15.0)
    c_light.setup_sky_light("Office_SkyLight", (0, 0, 500), 5.0)
