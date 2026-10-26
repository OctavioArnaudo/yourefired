# ============================================================
# YOU'RE FIRED - View: 2D Office Level Layout Orchestrator
# ============================================================
import unreal
import c_camera
import c_light
import v_office_perimeter
import v_office_cubicles
import v_office_actors
import v_office_items

def build_office_layout():
    """View: Orquestador descomprimido que delega cada componente del nivel a vistas especializadas."""
    unreal.log("[OfficeLevel] Orquestando diseño modular descomprimido de la oficina...")

    # 1. Perímetro y Suelo
    v_office_perimeter.build_office_perimeter(1600.0)

    # 2. Cubículos
    v_office_cubicles.build_office_cubicles()

    # 3. Personajes (Jugador y Enemigos)
    v_office_actors.place_office_actors()

    # 4. Ítems interactivos y Puerta
    v_office_items.place_office_items()

    # 5. Cámara ortográfica 2D e iluminación
    c_camera.spawn_or_update_camera("Office_TopDownCamera", (0, 0, 1500), (-90, 0, 0), ortho_width=2800.0)
    c_light.setup_directional_light("Office_DirectionalLight", (0, 0, 1000), (-90, 0, 0), 15.0)
    c_light.setup_sky_light("Office_SkyLight", (0, 0, 500), 5.0)
