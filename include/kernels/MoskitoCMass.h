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

#ifndef MOSKITOCMASS_H
#define MOSKITOCMASS_H

#include "Kernel.h"

class MoskitoCMass;

template <>
InputParameters validParams<MoskitoCMass>();

class MoskitoCMass : public Kernel
{
public:
  MoskitoCMass(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned jvar) override;

  // Coupled velocities
  const VariableValue & _q_vol;

  // Gradients of coupled velocities
  const VariableGradient & _grad_q_vol;

  // Variable numberings
  unsigned _q_vol_var_number;
  const MaterialProperty<Real> & _area;
  // Unit vector of well direction
  const MaterialProperty<RealVectorValue> & _well_dir;
};

#endif // MOSKITOCMASS_H
