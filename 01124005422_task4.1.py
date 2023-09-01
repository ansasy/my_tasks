import random

# Define classes for weapons and shields

class Weapon:
    def __init__(self, name, energy_cost, damage, resources):
        self.name = name
        self.energy_cost = energy_cost
        self.damage = damage
        self.resources = resources

class Shield:
    def __init__(self, name, energy_cost, save_percentage, resources):
        self.name = name
        self.energy_cost = energy_cost
        self.save_percentage = save_percentage
        self.resources = resources

# Define classes for villains

class Villain:
    def __init__(self, name, health=100, energy=500):
        self.name = name
        self.health = health
        self.energy = energy
        self.shield = None
        self.weapon = None  # Initialize weapon as None

class GruVillain(Villain):
    def choose_equipment(self):
        # Create a list of available weapons and shields for Gru
        weapons = [gweapon1, gweapon2, gweapon3, gweapon4]
        shields = [gshield1, gshield2]

        # Allow Gru to choose a weapon and shield randomly
        self.weapon = random.choice(weapons)
        self.shield = random.choice(shields)

    def attack(self, enemy):
        if self.weapon is not None:
            print(f"{self.name} attacks {enemy.name} with {self.weapon.name}!")
            damage = random.randint(self.weapon.damage - 2, self.weapon.damage + 2)
            enemy.health -= damage
            self.energy -= self.weapon.energy_cost
            print(f"{enemy.name} loses {damage} health.")
        else:
            print(f"{self.name} has no weapon to attack with!")

    def defend(self, enemy):
        if self.shield is not None:
            print(f"{self.name} raises a shield {self.shield.name} to defend against {enemy.name}'s attack.")

            # Calculate the damage reduction based on the shield's save_percentage
            damage_reduction = (self.shield.save_percentage / 100) * enemy.weapon.damage

            # Reduce the damage taken by the calculated damage reduction
            actual_damage = enemy.weapon.damage - damage_reduction
            if actual_damage < 0:
                actual_damage = 0  # Ensure damage doesn't go negative

            self.health -= actual_damage
            print(f"{enemy.name}'s attack is partially blocked. {self.name} loses {actual_damage} health.")
        else:
            print(f"{self.name} has no shield to defend with!")

# Create instances of weapons and shields for Gru
gweapon1 = Weapon("Freeze Gun", 50, 11, "Inf")
gweapon2 = Weapon("Electric Prod", 88, 18, 5)
gweapon3 = Weapon("Mega Magnet", 92, 10, 3)
gweapon4 = Weapon("Kalman Missile", 120, 20, 1)

gshield1 = Shield("Energy-Projected Barrier Gun", 20, 40, "inf")
gshield2 = Shield("Selective Permeability", 50, 90, 2)

class VectorVillain(Villain):
    def choose_equipment(self):
        # Create a list of available weapons and shields for Vector
        weapons = [vweapon1, vweapon2, vweapon3]
        shields = [vshield1, vshield2]

        # Allow Vector to choose a weapon and shield randomly
        self.weapon = random.choice(weapons)
        self.shield = random.choice(shields)

    def attack(self, enemy):
        if self.weapon is not None:
            print(f"{self.name} attacks {enemy.name} with {self.weapon.name}!")
            damage = random.randint(self.weapon.damage - 2, self.weapon.damage + 2)
            enemy.health -= damage
            self.energy -= self.weapon.energy_cost
            print(f"{enemy.name} loses {damage} health.")
        else:
            print(f"{self.name} has no weapon to attack with!")

    def defend(self, enemy):
        if self.shield is not None:
            print(f"{self.name} raises a shield {self.shield.name} to defend against {enemy.name}'s attack.")

            # Calculate the damage reduction based on the shield's save_percentage
            damage_reduction = (self.shield.save_percentage / 100) * enemy.weapon.damage

            # Reduce the damage taken by the calculated damage reduction
            actual_damage = enemy.weapon.damage - damage_reduction
            if actual_damage < 0:
                actual_damage = 0  # Ensure damage doesn't go negative

            self.health -= actual_damage
            print(f"{enemy.name}'s attack is partially blocked. {self.name} loses {actual_damage} health.")
        else:
            print(f"{self.name} has no shield to defend with!")

# Create instances of weapons and shields for Vector
vweapon1 = Weapon("Laser Blaster", 40, 8, "Inf")
vweapon2 = Weapon("Plasma Grenade", 56, 13, 8)
vweapon3 = Weapon("Sonic Resonance Cannon", 100, 22, 3)

vshield1 = Shield("Energy Net Trap", 15, 32, "inf")
vshield2 = Shield("Quantum Deflector", 40, 80, 3)

class Battle:
    def __init__(self):
        self.gru_villain = GruVillain("Gru")
        self.vector_villain = VectorVillain("Vector")
        self.rounds = 0

    def begin(self):
        while self.gru_villain.health > 0 and self.vector_villain.health > 0:
            self.rounds += 1
            print(f"Round {self.rounds}")

            # Gru and Vector choose their equipment
            self.gru_villain.choose_equipment()
            self.vector_villain.choose_equipment()

            while True:
                gru_choice = input(f"{self.gru_villain.name}, choose your action (attack/defend): ")
                vector_choice = input(f"{self.vector_villain.name}, choose your action (attack/defend): ")

                if gru_choice not in ["attack", "defend"] or vector_choice not in ["attack", "defend"]:
                    print("Invalid action! Please choose 'attack' or 'defend'.")
                else:
                    break

            if vector_choice =="defend" and gru_choice =="defend":
                print("Both villains chose to defend. Skipping the round.")
                continue
            if gru_choice not in ["attack", "defend"] or vector_choice not in ["attack", "defend"]:
                print("Invalid action! Skipping the round.")
                continue

            if gru_choice == "attack":
                self.gru_villain.attack(self.vector_villain)
            elif gru_choice == "defend":
                self.gru_villain.defend(self.vector_villain)


            if vector_choice == "attack":
                self.vector_villain.attack(self.gru_villain)
            elif vector_choice == "defend":
                self.vector_villain.defend(self.gru_villain)


            print(f"{self.gru_villain.name} Health: {self.gru_villain.health}")
            print(f"{self.vector_villain.name} Health: {self.vector_villain.health}")

        if self.gru_villain.health <= 0:
            print("Vector wins!")
        else:
            print("Gru wins!")

# Create a Battle instance and begin the battle
battle = Battle()
battle.begin()
