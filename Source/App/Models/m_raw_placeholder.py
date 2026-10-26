# ============================================================
# YOU'RE FIRED - Model: Unified Primary Asset Placeholder Definitions
# ============================================================
import unreal
import os

PROJECT_DIR = unreal.Paths.project_dir()
CONTENT_DIR = os.path.join(PROJECT_DIR, "Content", "YoureFired")

EXPECTED_RAW_TEXTURES = [
    # Jugador (Player)
    "Textures/Player/Player_Idle/Player_Idle_01.png",
    "Textures/Player/Player_Walk_Left/Player_Walk_Left_01.png",
    "Textures/Player/Player_Walk_Right/Player_Walk_Right_01.png",
    "Textures/Player/Player_Walk_Up/Player_Walk_Up_01.png",
    "Textures/Player/Player_Walk_Down/Player_Walk_Down_01.png",

    # Supervisor
    "Textures/Supervisor/Supervisor_Idle/Supervisor_Idle_01.png",
    "Textures/Supervisor/Supervisor_Walk_Left/Supervisor_Walk_Left_01.png",
    "Textures/Supervisor/Supervisor_Walk_Right/Supervisor_Walk_Right_01.png",
    "Textures/Supervisor/Supervisor_Walk_Up/Supervisor_Walk_Up_01.png",
    "Textures/Supervisor/Supervisor_Walk_Down/Supervisor_Walk_Down_01.png",

    # Compañero (Coworker)
    "Textures/Coworker/Coworker_Idle/Coworker_Idle_01.png",
    "Textures/Coworker/Coworker_Walk_Left/Coworker_Walk_Left_01.png",
    "Textures/Coworker/Coworker_Walk_Right/Coworker_Walk_Right_01.png",
    "Textures/Coworker/Coworker_Walk_Up/Coworker_Walk_Up_01.png",
    "Textures/Coworker/Coworker_Walk_Down/Coworker_Walk_Down_01.png",

    # Entorno y Mobiliario
    "Textures/Environment/Floor.png",
    "Textures/Environment/Wall.png",
    "Textures/Environment/Desk.png",
    "Textures/Environment/Chair.png",
    "Textures/Environment/Door.png",

    # Ítems y Pickups
    "Textures/Items/Coffee.png",
    "Textures/Items/Signature.png"
]

EXPECTED_RAW_MESHES = [
    "Meshes/FloorMain.fbx",
    "Meshes/WallNorth.fbx",
    "Meshes/CubicleDesk.fbx",
    "Meshes/CubicleChair.fbx",
    "Meshes/OfficeDoor.fbx",
    "Meshes/CoffeeItem.fbx",
    "Meshes/SignatureItem.fbx"
]
