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

#ifndef MOSKITOFLUIDWELLGENERAL_H
#define MOSKITOFLUIDWELLGENERAL_H

#include "Material.h"
#include "MoskitoViscosity.h"

class MoskitoFluidWellGeneral;

template <>
InputParameters validParams<MoskitoFluidWellGeneral>();

class MoskitoFluidWellGeneral : public Material
{
public:
  MoskitoFluidWellGeneral(const InputParameters & parameters);
  virtual void computeQpProperties() override;

protected:
  // Velocity in well
  MaterialProperty<Real> & _u;
  // Reynolds number in well
  MaterialProperty<Real> & _Re;
  // Moody friction coefficient
  MaterialProperty<Real> & _friction;
  // Well diameter
  MaterialProperty<Real> & _dia;
  // Well area
  MaterialProperty<Real> & _area;
  // unit vector along well
  MaterialProperty<RealVectorValue> & _well_unit_vect;
  // The gravity acceleration as a vector
  MaterialProperty<RealVectorValue> & _gravity;
  // temperature
  MaterialProperty<Real> & _T;
  // thermal conductivity of casing and fluid
  MaterialProperty<Real> & _lambda;
  // Direction of flow, the positive sign is production and vice versa
  MaterialProperty<Real> & _dir;

  // The coupled enthalpy
  const VariableValue & _h;
  // The coupled pressure
  const VariableValue & _P;
  // The coupled flow rate
  const VariableValue & _flow;

  // function to calculate friction factor using Moody chart
  void MoodyFrictionFactor(Real & friction, Real rel_roughness, Real ReNo, MooseEnum roughness_type);

  // function for calculating the unit vector of well orientation
  RealVectorValue WellUnitVector();

  // local variables
  RealVectorValue _g;
  Real _lambda0;
  Real _thickness;
  Real _d;
  Real _rel_roughness;
  Real _f;
  bool _f_defined;
  MooseEnum _roughness_type;
  MooseEnum _well_direction;
  const Real PI = 3.141592653589793238462643383279502884197169399375105820974944592308;
};

#endif /* MOSKITOFLUIDWELLGENERAL_H */
