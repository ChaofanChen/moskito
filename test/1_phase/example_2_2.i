# "Applied multiphase flow in pipes and flow assurance oil and gas production"
# Al-Safran, E., Brill, J. P., 2017
# Example 2.1: Determine the pipeline outlet pressure (injection)?

[Mesh]
  type = FileMesh
  file = example_2_2.msh
  uniform_refine = 2
[]

[UserObjects]
  [./eos]
    type = MoskitoEOS1P_IdealFluid
    bulk_modulus = 2e+012
    reference_density = 883
  [../]
  [./viscosity]
    type = MoskitoViscosityConst
    viscosity = 0.001
  [../]
[]

[Materials]
  [./area0]
    type = MoskitoFluidWell1P
    pressure = p
    enthalpy = h
    flowrate = q
    well_direction = x
    eos_uo = eos
    viscosity_uo = viscosity
    well_diameter = 0.1016
    roughness_type = smooth
    manual_friction_factor = 0.02
  [../]
[]

[BCs]
  [./pbcl]
    type = DirichletBC
    variable = p
    boundary = right
    value = 0
  [../]
  [./qbc]
    type = DirichletBC
    variable = q
    boundary = left
    value = -0.00223
  [../]
[]

[Variables]
  [./h]
    initial_condition = 0
  [../]
  [./p]
  [../]
  [./q]
    scaling = 1e-5
    initial_condition = -0.00223
  [../]
[]

[Kernels]
  [./hkernel]
    type = NullKernel
    variable = h
  [../]
  [./pkernel]
    type = MoskitoMass
    variable = p
    flowrate = q
    enthalpy = h
  [../]
  [./qkernel]
    type = MoskitoMomentum
    variable = q
    pressure = p
    enthalpy = h
  [../]
[]

[Preconditioning]
  [./p2]
    type = SMP
    full = true
    petsc_options_iname = '-pc_type -sub_pc_type -sub_pc_factor_shift_type -ksp_gmres_restart'
    petsc_options_value = 'asm lu NONZERO 51'
  [../]
[]

[Executioner]
  type = Steady
  l_tol = 1e-10
  l_max_its = 50
  nl_rel_tol = 1e-8
  nl_abs_tol = 1e-9
  nl_max_its = 50
  solve_type = NEWTON
[]

[Outputs]
  exodus = true
[]
