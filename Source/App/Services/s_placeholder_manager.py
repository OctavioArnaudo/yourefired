# ============================================================
# YOU'RE FIRED - Service: Asset Placeholder Manager
# ============================================================
import unreal
import os

def ensure_asset_placeholders():
    """Service: Verifica y genera físicamente los archivos .uasset en disco con prefijos estrictos por tipo."""
    unreal.log("[Service:PlaceholderManager] Verificando archivos .uasset físicos en disco (Content/YoureFired/)...")

    placeholders = [
        # Materiales (Prefijo M_)
        ("/Game/YoureFired/Materials/M_OfficeStyle.M_OfficeStyle", "/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"),
        ("/Game/YoureFired/Materials/M_UITheme.M_UITheme", "/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"),

        # Geometría base y entorno (Prefijo SM_)
        ("/Game/YoureFired/Meshes/SM_FloorMain.SM_FloorMain", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/SM_WallNorth.SM_WallNorth", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/SM_WallSouth.SM_WallSouth", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/SM_WallEast.SM_WallEast", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/SM_WallWest.SM_WallWest", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/SM_CubicleDesk.SM_CubicleDesk", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/SM_CubicleChair.SM_CubicleChair", "/Engine/BasicShapes/Cylinder.Cylinder"),

        # Personajes y Enemigos (Prefijo SM_)
        ("/Game/YoureFired/Meshes/SM_Player.SM_Player", "/Engine/BasicShapes/Sphere.Sphere"),
        ("/Game/YoureFired/Meshes/SM_CoworkerEnemy.SM_CoworkerEnemy", "/Engine/BasicShapes/Cylinder.Cylinder"),
        ("/Game/YoureFired/Meshes/SM_SupervisorEnemy.SM_SupervisorEnemy", "/Engine/BasicShapes/Cone.Cone"),

        # Pickups e Ítems (Prefijo SM_)
        ("/Game/YoureFired/Meshes/SM_CoffeeItem.SM_CoffeeItem", "/Engine/BasicShapes/Cylinder.Cylinder"),
        ("/Game/YoureFired/Meshes/SM_SignatureItem.SM_SignatureItem", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/SM_OfficeDoor.SM_OfficeDoor", "/Engine/BasicShapes/Cube.Cube"),
        ("/Game/YoureFired/Meshes/SM_WeaponBase.SM_WeaponBase", "/Engine/BasicShapes/Cone.Cone")
    ]

    content_dir = unreal.Paths.project_content_dir()

    for custom_path, source_base in placeholders:
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
                    new_asset = unreal.EditorAssetLibrary.load_asset(custom_path)
                    if new_asset:
                        unreal.EditorAssetLibrary.save_loaded_asset(new_asset)
                    unreal.log(f"[Service:PlaceholderManager] [CREADO EN DISCO] Archivo .uasset con prefijo generado: {disk_path}")
                else:
                    unreal.log_error(f"[Service:PlaceholderManager] Falló duplicate_asset para {custom_path}")
            except Exception as e:
                unreal.log_error(f"[Service:PlaceholderManager] Excepción al crear {custom_path}: {str(e)}")
        else:
            unreal.log(f"[Service:PlaceholderManager] [EXISTE EN DISCO] {disk_path}")

    unreal.log("[Service:PlaceholderManager] === VERIFICACION FISICA COMPLETADA ===")
