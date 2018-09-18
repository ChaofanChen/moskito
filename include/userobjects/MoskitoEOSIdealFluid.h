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

#ifndef MOSKITOEOSIDEALFLUID_H
#define MOSKITOEOSIDEALFLUID_H

#include "MoskitoEOS.h"

class MoskitoEOSIdealFluid;

template <>
InputParameters validParams<MoskitoEOSIdealFluid>();

class MoskitoEOSIdealFluid : public MoskitoEOS
{
public:
  MoskitoEOSIdealFluid(const InputParameters & parameters);

  virtual Real rho(Real pressure, Real temperature) const override;
  virtual void drho_dpT(
      Real pressure, Real temperature, Real & rho, Real & drho_dp, Real & drho_dT) const override;
  virtual void drho_dpT_2(
      Real pressure, Real temperature, Real & drho_dp_2, Real & drho_dT_2, Real & drho_dTdp) const override;
  virtual Real p(Real density, Real temperature) const override;
  virtual void dp_drhoT(
      Real density, Real temperature, Real & pressure, Real & dp_drho, Real & dp_dT) const override;
  virtual void
      dp_drhoT_2(Real density, Real temperature, Real & dp_drho_2, Real & dp_dT_2) const override;
  virtual Real h_to_T(Real enthalpy) const override;
  virtual Real T_to_h(Real temperature) const override;

protected:
  // thermal expansion coefficient
  const Real _thermal_expansion;
  // bulk modulus
  const Real _bulk_modulus;
};

#endif /* MOSKITOEOSIDEALFLUID_H */
