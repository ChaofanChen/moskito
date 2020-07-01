/**************************************************************************/
/*  MOSKITO - Multiphysics cOupled Simulator toolKIT for wellbOres        */
/*                                                                        */
/*  Copyright (C) 2017 by Maziar Gholami Korzani                          */
/*  Karlsruhe Institute of Technology, Institute of Applied Geosciences   */
/*  Division of Geothermal Research                                       */
/*                                                                        */
/*  This file is part of MOSKITO App                                      */
/*                                                                        */
/*  This program is free software: you can redistribute it and/or modify  */
/*  it under the terms of the GNU General Public License as published by  */
/*  the Free Software Foundation, either version 3 of the License, or     */
/*  (at your option) any later version.                                   */
/*                                                                        */
/*  This program is distributed in the hope that it will be useful,       */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of        */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          */
/*  GNU General Public License for more details.                          */
/*                                                                        */
/*  You should have received a copy of the GNU General Public License     */
/*  along with this program.  If not, see <http://www.gnu.org/licenses/>  */
/**************************************************************************/

#pragma once

#include "MoskitoFluidWellGeneral.h"
#include "MoskitoEOS2P.h"
#include "MoskitoViscosity2P.h"
#include "MoskitoDriftFlux.h"

class MoskitoFluidWell_2p1c;

template <>
InputParameters validParams<MoskitoFluidWell_2p1c>();

class MoskitoFluidWell_2p1c : public MoskitoFluidWellGeneral
{
public:
  MoskitoFluidWell_2p1c(const InputParameters & parameters);
  virtual void computeQpProperties() override;
  void PhaseVelocities();
  void GammaDerivatives();
  void KappaDerivatives();
  void OmegaDerivatives();
  Real gamma(const Real & h, const Real & p, const Real & v);
  Real kappa(const Real & h, const Real & p, const Real & v);
  Real omega(const Real & h, const Real & p, const Real & v);

protected:
  // Userobject to equation of state
  const MoskitoEOS2P & eos_uo;
  // Userobject to Viscosity Eq
  const MoskitoViscosity2P & viscosity_uo;
  // Userobject to Drift Fluc model
  const MoskitoDriftFlux & dfm_uo;

  // temperature
  MaterialProperty<Real> & _T;
  // The specific heat of mixture at constant pressure
  MaterialProperty<Real> & _cp_m;
  // Density of gas
  MaterialProperty<Real> & _rho_g;
  // Density of liquid
  MaterialProperty<Real> & _rho_l;
  // Density of mixture
  MaterialProperty<Real> & _rho_m;
  // Profile-adjusted density of mixture
  MaterialProperty<Real> & _rho_pam;
  // The first derivative of mixture density wrt pressure
  MaterialProperty<Real> & _drho_m_dp;
  // The second derivative of mixture density wrt pressure
  MaterialProperty<Real> & _drho_m_dp2;
  // The first derivative of mixture density wrt enthalpy
  MaterialProperty<Real> & _drho_m_dh;
  // The second derivative of mixture density wrt enthalpy
  MaterialProperty<Real> & _drho_m_dh2;
  // The second derivative of mixture density wrt enthalpy and pressure
  MaterialProperty<Real> & _drho_m_dph;
  // mass_fraction
  MaterialProperty<Real> & _vmfrac;
  // Gas velocity
  MaterialProperty<Real> & _u_g;
  // Liquid velocity
  MaterialProperty<Real> & _u_l;

  // void_fraction
  MaterialProperty<Real> & _vfrac;
  // current phase
  MaterialProperty<Real> & _phase;
  // drift velocity
  MaterialProperty<Real> & _u_d;
  // flow type parameter
  MaterialProperty<Real> & _c0;
  // flow pattern
  MaterialProperty<Real> & _flow_pat;

  // The gamma first derivatives
  MaterialProperty<Real> & _dgamma_dp;
  // The gamma first derivatives
  MaterialProperty<Real> & _dgamma_dh;
  // The gamma first derivatives
  MaterialProperty<Real> & _dgamma_dv;
  // The gamma second derivatives
  MaterialProperty<Real> & _dgamma_dph;
  // The gamma second derivatives
  MaterialProperty<Real> & _dgamma_dpv;
  // The gamma second derivatives
  MaterialProperty<Real> & _dgamma_dhv;
  // The gamma second derivatives
  MaterialProperty<Real> & _dgamma_dp2;
  // The gamma second derivatives
  MaterialProperty<Real> & _dgamma_dh2;
  // The gamma second derivatives
  MaterialProperty<Real> & _dgamma_dv2;

  // The kappa first derivatives
  MaterialProperty<Real> & _dkappa_dp;
  // The kappa first derivatives
  MaterialProperty<Real> & _dkappa_dh;
  // The kappa first derivatives
  MaterialProperty<Real> & _dkappa_dv;
  // The kappa second derivatives
  MaterialProperty<Real> & _dkappa_dph;
  // The kappa second derivatives
  MaterialProperty<Real> & _dkappa_dpv;
  // The kappa second derivatives
  MaterialProperty<Real> & _dkappa_dhv;
  // The kappa second derivatives
  MaterialProperty<Real> & _dkappa_dp2;
  // The kappa second derivatives
  MaterialProperty<Real> & _dkappa_dh2;
  // The kappa second derivatives
  MaterialProperty<Real> & _dkappa_dv2;

  // The omega first derivatives
  MaterialProperty<Real> & _domega_dp;
  // The omega first derivatives
  MaterialProperty<Real> & _domega_dh;
  // The omega first derivatives
  MaterialProperty<Real> & _domega_dv;
  // The omega second derivatives
  MaterialProperty<Real> & _domega_dph;
  // The omega second derivatives
  MaterialProperty<Real> & _domega_dpv;
  // The omega second derivatives
  MaterialProperty<Real> & _domega_dhv;
  // The omega second derivatives
  MaterialProperty<Real> & _domega_dp2;
  // The omega second derivatives
  MaterialProperty<Real> & _domega_dh2;
  // The omega second derivatives
  MaterialProperty<Real> & _domega_dv2;

  // The coupled enthalpy
  const VariableValue & _h;
  const VariableValue & _m;

  // The gradient of the coupled variables
  const VariableGradient & _grad_m;
  const VariableGradient & _grad_h;
  const VariableGradient & _grad_p;
};
