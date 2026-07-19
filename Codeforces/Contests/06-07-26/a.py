trials_completados = [t for t in study_entrenamiento.trials if t.state == optuna.trial.TrialState.COMPLETE]
trials_podados      = [t for t in study_entrenamiento.trials if t.state == optuna.trial.TrialState.PRUNED]
trials_fallidos     = [t for t in study_entrenamiento.trials if t.state == optuna.trial.TrialState.FAIL]

print("="*60)
print("RESUMEN ETAPA B — OPTIMIZACIÓN DE ENTRENAMIENTO")
print("="*60)
print(f"Total de trials registrados:   {len(study_entrenamiento.trials)}")
print(f"  -> Completados exitosamente: {len(trials_completados)}")
print(f"  -> Podados (pruned):         {len(trials_podados)}")
print(f"  -> Fallidos:                 {len(trials_fallidos)}")

trials_nan = [t for t in trials_completados if t.value is not None and np.isnan(t.value)]
print(f"  -> Completados con valor NaN: {len(trials_nan)}")

print("\n" + "-"*60)
print("MEJOR TRIAL ENCONTRADO")
print("-"*60)
if len(trials_completados) > 0:
    print(f"Trial número: {study_entrenamiento.best_trial.number}")
    print(f"Val Loss:     {study_entrenamiento.best_trial.value:.6f}")
    print(f"\nHiperparámetros de entrenamiento:")
    for k, v in study_entrenamiento.best_trial.params.items():
        print(f"  {k}: {v}")
    print(f"\nTiempo del trial: {study_entrenamiento.best_trial.user_attrs.get('tiempo_trial_seg', 'N/D')}")
else:
    print("⚠️ Ningún trial se completó con éxito.")

print("\n" + "-"*60)
print("TOP 5 MEJORES TRIALS (por Val Loss)")
print("-"*60)
trials_df = study_entrenamiento.trials_dataframe()
trials_df_validos = trials_df[trials_df['state'] == 'COMPLETE'].sort_values('value')
cols_mostrar = ['number', 'value'] + [c for c in trials_df_validos.columns if c.startswith('params_')]
print(trials_df_validos[cols_mostrar].head(5).to_string())

from optuna.importance import FanovaImportanceEvaluator
evaluador_fijo = FanovaImportanceEvaluator(seed=SEED)

print("\n" + "-"*60)
print("IMPORTANCIA DE HIPERPARÁMETROS")
print("-"*60)
try:
    importancias_reproducibles = optuna.importance.get_param_importances(
        study_entrenamiento, evaluator=evaluador_fijo
    )
    for k, v in importancias_reproducibles.items():
        print(f"  {k}: {v:.4f}")
except Exception as e:
    print(f"No se pudo calcular importancia (default): {e}")

print("\n" + "-"*60)
print("TIEMPO TOTAL DE LA ETAPA")
print("-"*60)
tiempos = [t.user_attrs.get('tiempo_trial_seg', 0) for t in trials_completados]
if tiempos:
    print(f"Tiempo total acumulado en trials completados: {sum(tiempos)/3600:.2f} horas")
    print(f"Tiempo promedio por trial completado:         {np.mean(tiempos)/60:.1f} minutos")

# --- Gráfico de importancia ---
import optuna.visualization.matplotlib as vis_mpl

vis_mpl.plot_param_importances(study_entrenamiento, evaluator=evaluador_fijo)
plt.tight_layout()
plt.show()