# ============================================================
# YOU'RE FIRED - Service: Asset Name Normalizer
# ============================================================
import unreal

def get_normalized_asset_name(name):
    """Service: Normaliza nombres de instancias (ej. Cubicle_01_Desk) a su nombre base de placeholder."""
    if "Cubicle" in name and "Desk" in name:
        return "Cubicle_Desk"
    if "Cubicle" in name and "Chair" in name:
        return "Cubicle_Chair"
    if "Coworker" in name:
        return "CoworkerEnemy"
    if "Supervisor" in name:
        return "SupervisorEnemy"
    if "Coffee" in name:
        return "CoffeeItem"
    if "Signature" in name:
        return "SignatureItem"
    if "Door" in name:
        return "OfficeDoor"
    if "Weapon" in name:
        return "WeaponBase"
    if "Player" in name:
        return "Player_Worker"
    return name
