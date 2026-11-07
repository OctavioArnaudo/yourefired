# ============================================================
# YOU'RE FIRED - Service : Range Distance Computation Service
# ============================================================
import unreal

class SRangeService:
    """Service: Logica de calculo de distancias y overlaps."""

    def calculate_distance(self, loc_a, loc_b):
        vec_a = unreal.Vector(loc_a[0], loc_a[1], loc_a[2])
        vec_b = unreal.Vector(loc_b[0], loc_b[1], loc_b[2])
        dist = vec_a.distance(vec_b) if hasattr(vec_a, 'distance') else 0.0
        unreal.log(f"[SRangeService] Distancia calculada: {dist}")
        return dist
