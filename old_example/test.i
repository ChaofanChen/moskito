[Mesh]
  type = GeneratedMesh
  dim = 1
  xmin = 0
  xmax = 1
  nx = 5
[]

[UserObjects]
  [./eos_g]
    type = MoskitoEOSIdealFluid
    reference_density = 1
    reference_enthalpy = 0
    reference_pressure = 0
    reference_temperature = 0
  [../]
  [./eos_l]
    type = MoskitoEOSIdealFluid
    reference_density = 1000
    reference_enthalpy = 0
    reference_pressure = 0
    reference_temperature = 0
  [../]
  [./eos_2p]
    type = MoskitoEOS2P
    eos_uo_gas = eos_g
    eos_uo_liquid = eos_l
  [../]
  [./ve_g]
    type = MoskitoViscosityConst
    viscosity = 0.00001
  [../]
  [./ve_l]
    type = MoskitoViscosityConst
    viscosity = 0.001
  [../]
  [./ve_2p]
    type = MoskitoViscosity2P
    ve_uo_gas = ve_g
    ve_uo_liquid = ve_l
    mixing_type = Mean_ME12
  [../]
[]

# [Functions]
#   [./void]
#     type = ParsedFunction
#     value = 'x'
#   [../]
# []

[Materials]
  [./g]
    type = GenericConstantMaterial
    prop_names = 'drift_velocity flow_type_c0 void_fraction'
    prop_values = '1.094 1.0 0.65'
    output_properties = 'void_fraction drift_velocity'
    outputs = exodus
  [../]
  # [./v]
  #   type = GenericFunctionMaterial
  #   prop_names = 'void_fraction'
  #   prop_values = 'void'
  #   outputs = exodus
  # [../]
  [./area0]
    type = MoskitoFluidWell2P
    pressure = p
    enthalpy = h
    flowrate = q
    well_direction = x
    eos_uo = eos_2p
    viscosity_uo = ve_2p
    well_diameter = 0.2034
    manual_friction_factor = 0
    output_properties = 'well_area gas_velocity liquid_velocity profile_mixture_density gas_density liquid_density density well_velocity'
    outputs = exodus
  [../]
[]

[Variables]
  [./h]
  [../]
  [./p]
  [../]
  [./q]
    initial_condition = 0.040759
  [../]
[]

[Kernels]
  [./hkernel]
    type = NullKernel
    variable = h
  [../]
  [./pkernel]
    type = NullKernel
    variable = p
  [../]
  [./qkernel]
    type = NullKernel
    variable = q
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
