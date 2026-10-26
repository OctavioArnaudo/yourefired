# ============================================================
# YOU'RE FIRED - Service: Static Mesh Placeholder (SM_)
# ============================================================
import unreal
import os

def ensure_sm_placeholders():
    unreal.log("[Service:SM_Placeholder] Verificando Static Meshes (SM_)...")
    meshes = [
        ("/Game/YoureFired/Meshes/SM_FloorMain.SM_FloorMain", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/SM_WallNorth.SM_WallNorth", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/SM_WallSouth.SM_WallSouth", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/SM_WallEast.SM_WallEast", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/SM_WallWest.SM_WallWest", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/SM_CubicleDesk.SM_CubicleDesk", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/SM_CubicleChair.SM_CubicleChair", "/Engine/BasicShapes/Cylinder.Cylinder"),
        ("/Game/YoureFired/Meshes/SM_Player.SM_Player", "/Engine/BasicShapes/Sphere.Sphere"),
        ("/Game/YoureFired/Meshes/SM_CoworkerEnemy.SM_CoworkerEnemy", "/Engine/BasicShapes/Cylinder.Cylinder"),
        ("/Game/YoureFired/Meshes/SM_SupervisorEnemy.SM_SupervisorEnemy", "/Engine/BasicShapes/Cone.Cone"),
        ("/Game/YoureFired/Meshes/SM_CoffeeItem.SM_CoffeeItem", "/Engine/BasicShapes/Cylinder.Cylinder"),
        ("/Game/YoureFired/Meshes/SM_SignatureItem.SM_SignatureItem", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/SM_OfficeDoor.SM_OfficeDoor", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/SM_WeaponBase.SM_WeaponBase", "/Engine/BasicShapes/Cone.Cone")
    ]
    content_dir = unreal.Paths.project_content_dir()
    for custom_path, source_base in meshes:
        relative_path = custom_path.replace("/Game/", "").split(".")[0] + ".uasset"
        disk_path = os.path.join(content_dir, relative_path)
        if not os.path.exists(disk_path):
            parts = custom_path.split(".")
            object_path = parts[0]
            package_path = object_path.rsplit("/", 1)[0]
            if not unreal.EditorAssetLibrary.does_directory_exist(package_path):
                unreal.EditorAssetLibrary.make_directory(package_path)
            try:
                success = unreal.EditorAssetLibrary.duplicate_asset(source_base, object_path)
                if success:
                    asset = unreal.EditorAssetLibrary.load_asset(custom_path)
                    if asset:
                        unreal.EditorAssetLibrary.save_loaded_asset(asset)
                    unreal.log(f"[Service:SM_Placeholder] Creado: {disk_path}")
            except Exception as e:
                unreal.log_error(f"[Service:SM_Placeholder] Error en {custom_path}: {e}")
