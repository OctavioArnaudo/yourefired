import unreal
from .m_enemy import MEnemyData

class MCoworkerEnemyData(MEnemyData):
    """Model data for Coworker Enemy (melee gossip attacker)."""
    def __init__(self):
        super().__init__(damage=15.0, speed=350.0)
        self.gossip_radius = 200.0
