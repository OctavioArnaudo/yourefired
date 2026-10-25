import unreal
from .m_enemy import MEnemyData

class MSupervisorEnemyData(MEnemyData):
    """Model data for Supervisor Enemy (ranged reprimand attacker)."""
    def __init__(self):
        super().__init__(damage=25.0, speed=250.0)
        self.reprimand_range = 800.0
