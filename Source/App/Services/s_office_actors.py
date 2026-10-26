# ============================================================
# YOU'RE FIRED - Service : OfficeActors
# ============================================================
import unreal

def process_office_actors_service(data_model=None):
    """Service: Algoritmo de servicio y procesamiento lógico para OfficeActors."""
    unreal.log("[Service:OfficeActors] Procesando servicio especializado para OfficeActors.")
    if data_model:
        return data_model.is_active
    return True
