# Lootexample

Showcase: https://www.youtube.com/watch?v=WFJAFDt9F_8

Design statements: 
Easy to impliment 
Easy to adjust (weights and types)
Easy to add new items in pool 

Implementation:
1. Assign BP_LootGeneration component to actor
2. Adjust weights for BP_LootGeneration in Actor properties (LootWeights)
3. Make trigger to call Generate(int GenerateAmount) from Actor with passing amount of loot position to generate
4. ...
5. PROFIT

Loot generation logic:
1. Choosing type of generating loot from ENUM_LootType based on adjusted weights BP_LootGeneration->LootTypeWeights 
//this will return Weapon-Armour-Jewelry-Consumable type of loot
2. Based on random-weighted type choosed, run same logic for spawn exact loot type, adding RarityType and execute init methods to set mesh e.t.c
//For example if LootType:Weapon choosed, runs same logic to calculate weights but using BP_LootGeneration->WeaponTypeWeights for calculations
//There is just one moment makes me feel unsatisfied - if DT_Weapon will have more than one row with same type, there will be pure random for spawn item type. e.g. random wepon with type of Sword.
//So at the end exact sword base chanse ~= LootTypeWeight/LootTypeWeightSum + WeaponTypeWeight/WeaponTypeWeightSum + Sword/SwordSum
//For another loot choosing logic we need to impliment weight for each base in DT_'s. Not necessary for my experiment

Rarity logic:
Rarity represents as something global, so store probabilities in actors is not what i want. Rarity made as DT_RarityType for simple global adjastment. 
Rarity weight table is creating on BeginPlay in GameMode, so each item could get chanses when generating. Also, in cases where we have dynamic probability on new level we could just make multiplier for each type base on our goal.

Loot Struct view:
Each item of each type have some specific numbers, as min-max damage or defence. We dont need to store all numbers in one DT. 
So, idea is around hard stats. Weapon have identical stats, Armour have their own. The could be douvbled, but base struct must be separated.
After we assign DT row to item we also could get base stats as well. Other stats will be generated after this based on rarity, item type and special effects.






Assets credits:
swords pack -> https://sketchfab.com/3d-models/sword-kit-361d8d01c4014ed1b520ad371939c8e8 
bow pack -> https://sketchfab.com/3d-models/bow-kit-b3bd7dadee054402b2dbdc9ce217c280
helmet1 -> https://sketchfab.com/3d-models/vietnam-war-era-m1-helmet-c4009bdb0f1b4510b710bd3c8d4aa033
helmet2 -> https://sketchfab.com/3d-models/horn-helmet-sj03-04-45e5f6f6ffc74cfb88f6c0e50394c49f
helmet3 -> https://sketchfab.com/3d-models/battle-scarred-mandalorian-helmet-41c5e6a7dda4469cbb50c888264664b3
gloves1 -> https://sketchfab.com/3d-models/gloves-scanned-87e0b2c0fc814b1988a0d97754d64ce0
gloves2 -> https://sketchfab.com/3d-models/iron-glove-a5bc047bb07e4fc8a025e59023455b62
gloves3 -> https://sketchfab.com/3d-models/mechanical-gloves-f3fed278f56e49528c78e6c4c311777d
boots1 -> https://sketchfab.com/3d-models/kirza-boots-fac9f2745c0f47f5b4e63e2aaf8228f8
boots2 -> https://sketchfab.com/3d-models/women-combat-boots-f1e9d6761743404e936ecbecc75ca17c
boots3 -> https://sketchfab.com/3d-models/hiking-boots-lowpoly-1f25fa279bdc4f87b1374566e9e62923
chest1 -> https://sketchfab.com/3d-models/free-man-armor-2-d022fc3857104da59e286822c20868e1
chest2 -> https://sketchfab.com/3d-models/free-game-armor-1-9f423d363c9e4c01b6efffaef0b1180b
chest3 -> https://sketchfab.com/3d-models/armor-6a7bec36d57548ad86841f808f847bb0
ring1 -> https://sketchfab.com/3d-models/an-old-ring-ea5e0c11f2e046c993239ea1a3efcad7
necklace1 -> https://sketchfab.com/3d-models/aventurine-necklace-1793c52e7de041beafa8773a47c69505
belt1 -> https://sketchfab.com/3d-models/toolbelt-058ac6996c7d4c60960311d3b9ece0f3
Consumables -> https://sketchfab.com/3d-models/celtias-potion-consumables-86710e09f90f4752a017389ebada164e


