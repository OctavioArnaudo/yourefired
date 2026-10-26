# ============================================================
# YOU'RE FIRED - Service: HUD Progress & Stress Calculation
# ============================================================
import unreal

def calculate_stress_increment(time_in_office, nearby_enemies_count):
    """Service: Calcula el incremento progresivo de estrés del jugador."""
    base_stress = time_in_office * 0.5
    enemy_multiplier = nearby_enemies_count * 2.0
    return min(100.0, base_stress + enemy_multiplier)
