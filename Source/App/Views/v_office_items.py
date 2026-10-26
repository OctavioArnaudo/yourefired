# ============================================================
# YOU'RE FIRED - View: Office Pickups & Interactive Items Layout
# ============================================================
import unreal
import c_actor_spawner

def place_office_items():
    """View: Posiciona exclusivamente ítems interactivos (Café, Firmas, Puerta) en la oficina."""
    unreal.log("[View:OfficeItems] Posicionando ítems interactivos y puerta de salida...")
    c_actor_spawner.spawn_actor("CoffeeItem", "/Script/App.CCoffeePickup", (300, -800, 0))
    c_actor_spawner.spawn_actor("SignatureItem", "/Script/App.CSignaturePickup", (0, -600, 0))
    c_actor_spawner.spawn_actor("FloorExit_Door", "/Script/App.CDoor", (0, 1500, 0))
