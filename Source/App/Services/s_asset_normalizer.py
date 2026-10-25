# ============================================================
# YOU'RE FIRED - Service: Asset Name Normalizer
# ============================================================
import unreal

def get_normalized_asset_name(name):
    """Service: Normaliza nombres de instancias a su nombre base estricto con prefijos obligatorios (SM_, M_, etc.)."""
    if "Floor" in name:
        return "SM_FloorMain"
    if "Wall" in name and "North" in name:
        return "SM_WallNorth"
    if "Wall" in name and "South" in name:
        return "SM_WallSouth"
    if "Wall" in name and "East" in name:
        return "SM_WallEast"
    if "Wall" in name and "West" in name:
        return "SM_WallWest"
    if "Cubicle" in name and "Desk" in name:
        return "SM_CubicleDesk"
    if "Cubicle" in name and "Chair" in name:
        return "SM_CubicleChair"
    if "Coworker" in name:
        return "SM_CoworkerEnemy"
    if "Supervisor" in name:
        return "SM_SupervisorEnemy"
    if "Coffee" in name:
        return "SM_CoffeeItem"
    if "Signature" in name:
        return "SM_SignatureItem"
    if "Door" in name:
        return "SM_OfficeDoor"
    if "Weapon" in name:
        return "SM_WeaponBase"
    if "Player" in name:
        return "SM_Player"

    # Si ya tiene prefijo válido, respetarlo
    if name.startswith(("SM_", "SK_", "M_", "MI_", "BP_", "WBP_", "Lvl_", "T_", "S_")):
        return name

    return "SM_" + name
