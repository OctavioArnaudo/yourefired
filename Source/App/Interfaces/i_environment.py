# ============================================================
# YOU'RE FIRED - Interface : Environment
# ============================================================
import unreal

class IEnvironmentInterface:
    """Interface: Contrato para Environment."""
    def execute_environment(self):
        raise NotImplementedError("execute_environment debe ser implementado")
